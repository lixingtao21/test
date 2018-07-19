
#include <iostream>
#include <sstream>
#include <memory>
#include <json/json.h>
using namespace Json;
int main(int argc, char** argv)
{

	std::unique_ptr<Json::StreamWriter> writer(Json::StreamWriterBuilder().newStreamWriter());
	Json::Value array, element;
	element["face_id"] = "a9cebf8d5ae6fff514d8d2d8e07fa55b";
	element["similarity"] = 100;
	element["img_id"] = "12.jpg";
	element["people_name"] = "张艺谋";
	array["result"].append(element);
	element["face_id"] = "7f2de0e85bede3171c839d0dcabd849f";
	element["similarity"] = 55.379097;
	element["img_id"] = "6.jpg";
	element["people_name"] = "曾国藩";
	array["result"].append(element);
	element["face_id"] = "40ebb31e8af7237a73dec9f242885a7e";
	element["similarity"] = 52.59766;
	element["img_id"] = "2.jpg";
	element["people_name"] = "测试";
	array["result"].append(element);
	/*std::stringstream stream;
	if (writer->write(array, &stream))
		std::cout << "write failed" << std::endl;
	else
		std::cout << "II";

	std::string jsonStr = stream.str();*/
	string jsonStr = array.toStyledString(); //json字符串

	Json::CharReaderBuilder builder;
	builder["collectComments"] = false;
	Json::Value jsonRoot;

	JSONCPP_STRING errs;
	Json::CharReader* reader = builder.newCharReader();
	if (!reader->parse(jsonStr.data(), jsonStr.data() + jsonStr.size(), &jsonRoot, &errs)) //从jsonStr中读取数据到jsonRoot
	{
		return 0;
	}
	for (int i = 0; i < jsonRoot["result"].size();i++)
	{
		std::cout << jsonRoot["result"][i]["face_id"] << std::endl;
	}
return 0;
｝
