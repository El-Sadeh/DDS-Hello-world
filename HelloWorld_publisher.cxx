

#include <iostream>
#include <random>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()

#include "HelloWorld.hpp"

void publisher_main(int domain_id, int sample_count)
{
    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant (domain_id);

    // Create a Topic -- and automatically register the type
    dds::topic::Topic<TemperatureStruct> topic (participant, "Example TemperatureStruct");

    // Create a DataWriter with default Qos (Publisher created in-line)
    dds::pub::DataWriter<TemperatureStruct> writer(dds::pub::Publisher(participant), topic);
	
	//Great for using this.
	std::default_random_engine generator;
	std::uniform_int_distribution<> distribution(0, 100);

    TemperatureStruct sample;
    for (int count = 0; count < sample_count || sample_count == 0; count++) {
		  // generates number in the range 0...100
		sample.temp((short)distribution(generator));
		std::cout << "Writing TemperatureStruct, count " << count << std::endl;
        writer.write(sample);

        rti::util::sleep(dds::core::Duration(0,50000000));
    }
}

int main(int argc, char *argv[])
{

    int domain_id = 0;
    int sample_count = 0; // infinite loop

    if (argc >= 2) {
        domain_id = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

    // To turn on additional logging, include <rti/config/Logger.hpp> and
    // uncomment the following line:
    // rti::config::Logger::instance().verbosity(rti::config::Verbosity::STATUS_ALL);

    try {
        publisher_main(domain_id, sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in publisher_main(): " << ex.what() << std::endl;
        return -1;
    }

    // RTI Connext provides a finalize_participant_factory() method
    // if you want to release memory used by the participant factory singleton.
    // Uncomment the following line to release the singleton:
    //
    // dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}

