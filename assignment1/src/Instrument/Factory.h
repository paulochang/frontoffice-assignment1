#ifndef FACTORY_H
#define FACTORY_H

#include "../Leg/leg.h"

struct InstrumentDescription {
	enum Type {bond, swap};
	Type type;
	InstrumentDescription(Type type_):type(type_){} 
	LegDescription payer;
	LegDescription receiver;
};


class Factory {

	public:

		std::unique_ptr<IPricer> operator() (const InstrumentDescription& description) const;
		
		virtual ~Factory();
		
		typedef std::function<std::unique_ptr<IPricer>(const InstrumentDescription&)> Builder; 
		
		void register_constructor(const InstrumentDescription::Type& id, const Builder& builder);
		
		//singleton implementation ....
  	static Factory& instance() {
			
			static Factory factory;
			return factory;
		}
		
	
	private:
		
		Factory();
			
		InstrumentDescription::Type getBuilderId(const InstrumentDescription& description) const;
		
		std::map<InstrumentDescription::Type, Builder> buildersMap_;
};


std::unique_ptr<IPricer> Factory::operator()(const InstrumentDescription& description) c {
	
	auto builder = buildersMap_.find(getBuilderId(description));
	
	if (builder == buildersMap_.end()) {
		
		throw std::runtime_error("invalid payoff descriptor"); 
	};
	
	return (builder->second)(description);
}


InstrumentDescription::Type Factory::getBuilderId(const InstrumentDescription& description) {
	
	return description.type; 

}

void Factory::register_constructor(const InstrumentDescription::Type& id, const Builder& buildersMap_) {
	
	buildersMap_.insert(std::make_pair(id, builder));

}

template<typename BuilderClass> class FactoryRegistrator {

public:
   FactoryRegistrator() {
   	Factory::instance().register_constructor(BuilderClass::getId(), &BuilderClass::build);
	} 
};

#endif
