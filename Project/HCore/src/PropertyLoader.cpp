#include <PropertyLoader.h>

/* FACADE INCLUDES */
#include <tinyxml2.h>
#include <string>

/* NAMESPACE */
using namespace std;

//PRIVATE
/**
 * @brief Hides the implementation of the property reader. Now we are
 * using tinyxml as a secondary project.
 */
class PropertyLoader::Facade {
public:
	tinyxml2::XMLDocument		mProperties; /**< Actual document loaded. */
	string						mPropertiesName; /**< Name of the actual document loaded. */
};

PropertyLoader::PropertyLoader():
	pImpl(new Facade()){
	
}

PropertyLoader::~PropertyLoader(){}

//PUBLIC
bool PropertyLoader::loadProperties(string propertiesPath){
	//Do not load the same properties file that was loaded previously. Speed issues.
	bool isLoaded = true;
	if(propertiesPath != pImpl->mPropertiesName){
		//When loaded save the name of the document in mPropertiesName
		isLoaded = !pImpl->mProperties.LoadFile(propertiesPath.c_str());
		isLoaded ? pImpl->mPropertiesName = propertiesPath: pImpl->mPropertiesName.clear();
	}
	return isLoaded;
}

bool PropertyLoader::propertiesLoaded(){
	//Check if empty
	return !pImpl->mPropertiesName.empty();
}

string PropertyLoader::getPropertyValue(string propertyKey){
	//Get the property elements
	tinyxml2::XMLNode* propertiesElement = pImpl->mProperties.FirstChildElement("properties");
	tinyxml2::XMLElement* selectedProperty = propertiesElement->FirstChildElement("property");
	//Search for the key
	bool finished = false;
	while (!finished && selectedProperty->Attribute("key") != propertyKey){
		selectedProperty = selectedProperty->NextSiblingElement("property");
		finished = !selectedProperty;
	}
	if(selectedProperty) return selectedProperty->GetText();
	return NULL;
}

string PropertyLoader::getPropertyFileName(){
	return pImpl->mPropertiesName;
}