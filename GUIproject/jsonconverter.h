#pragma once

#include <cliext/vector>
using namespace System::Text;

using namespace System;
using namespace System::Collections::Generic;

ref class Tree {
private:
    ref class Node {
    public:
        String^ name;
        String^ data;
        List<Node^>^ children;
        Node^ parent;
        int depth;

        Node(String^ name);
    };

    Node^ root;
    Node^ current;
    int height;

    void DepthFirstTraversal(Node^ node, StringBuilder^ json, int indentLevel);
    String^ EscapeJsonString(String^ input);

public:
    Tree(String^ rootName);
    void AddNode(String^ nodeName);
    void AddData(String^ data);
    void MoveToParent();
    bool MoveToChild(int index);
    int GetHeight();
    String^ GetCurrentNodeName();
    String^ ToJSON();
};
ref class JSONConverter {
public:
    static void ConvertToJSON(System::IO::StreamReader^ input, String^ outputFileName);

private:
    static void ParseXMLNode(System::Xml::XmlNode^ xmlNode, Tree^ tree);
};