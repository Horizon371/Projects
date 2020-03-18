#include "Controller.h"
#include "Exception.h"
class UI {

private:
	Controller controller;
	int materialParser = -1;

public:
	UI(Controller c) : controller(c) {}

	void UImenu();

	void UIAdd(const std::string& id, const std::string& size,
		const float &radioactivityLevel, const int& quantityOfMicrofragments, const std::string& digitizedScan);

	void UIUpdate(const std::string& id, const std::string& size,
		const float &radioactivityLevel, const int& quantityOfMicrofragments, const std::string& digitizedScan);

	void UIDelete(const std::string &id);

	void UIList();

	void UIListMicrofragmentsAndSize(const std::string & size, int quantityOfMicrofragments);

	void UINext();

	void ListMyList();

	void UISaveId(const std::string &id);

	void UIReadFromFile(const std::string filePath);

	void UIChangeFile(const std::string filePath);

	void UIChangeMyListHTML(const std::string mylistPath);

	void UIChangeMyListCSV(const std::string mylistPath);

	~UI();

};