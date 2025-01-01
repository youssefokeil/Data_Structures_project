#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <string>
#include "User.h"
#include <vector>

void parseXML(std::string xml_path, std::map<int, User>& id_to_users);
void draw(std::map<int, User>& id_to_users, std::string graph_path);

std::vector<std::vector<std::string>> parseXMLToVector(const std::string& filename);

#endif // UTILS_H#pragma once
