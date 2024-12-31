#include "jsonconverter.h"

// Constructor for Node
Tree::Node::Node(String^ name) {
    this->name = name;
    this->data = "";
    this->children = gcnew List<Node^>();
    this->parent = nullptr;
    this->depth = 0;
}

// Constructor for Tree
Tree::Tree(String^ rootName) {
    root = gcnew Node(rootName);
    current = root;
    height = 0;
}

// Add a new node under the current node
void Tree::AddNode(String^ nodeName) {
    Node^ newNode = gcnew Node(nodeName);
    current->children->Add(newNode);
    newNode->parent = current;
    newNode->depth = current->depth + 1;
    current = newNode;
    height = Math::Max(height, newNode->depth);
}

// Add data to the current node
void Tree::AddData(String^ data) {
    current->data = data;
}

// Move up to the parent node
void Tree::MoveToParent() {
    if (current != root) {
        current = current->parent;
    }
}

// Move to a child node at a specific index
bool Tree::MoveToChild(int index) {
    if (index >= 0 && index < current->children->Count) {
        current = current->children[index];
        return true;
    }
    return false;
}

// Get the height of the tree
int Tree::GetHeight() {
    return height;
}

// Get the name of the current node
String^ Tree::GetCurrentNodeName() {
    return current->name;
}

// Escape special characters for JSON
String^ Tree::EscapeJsonString(String^ input) {
    // Remove leading/trailing whitespace and excessive newlines
    input = input->Trim();

    // Replace newlines and multiple spaces with a single space for better readability
    input = input->Replace("\r\n", " ");
    input = input->Replace("\n", " ");
    input = input->Replace("\r", " ");
    input = input->Replace("\t", " ");

    // Escape special JSON characters
    input = input->Replace("\"", "\\\"");
    input = input->Replace("\\", "\\\\");
    input = input->Replace("\n", "\\n");
    input = input->Replace("\r", "\\r");
    input = input->Replace("\t", "\\t");

    return input;
}


// Recursive tree traversal to generate JSON
void Tree::DepthFirstTraversal(Node^ node, StringBuilder^ json, int indentLevel) {
    String^ indent = String::Concat(gcnew String(' ', indentLevel * 2));

    json->Append(indent + "{\n");
    json->Append(indent + "  \"name\": \"" + EscapeJsonString(node->name) + "\"");

    if (!String::IsNullOrEmpty(node->data)) {
        json->Append(",\n" + indent + "  \"data\": \"" + EscapeJsonString(node->data) + "\"");
    }

    if (node->children->Count > 0) {
        json->Append(",\n" + indent + "  \"children\": [\n");

        for (int i = 0; i < node->children->Count; i++) {
            DepthFirstTraversal(node->children[i], json, indentLevel + 1);
            if (i < node->children->Count - 1) {
                json->Append(",\n");
            }
        }

        json->Append("\n" + indent + "  ]");
    }

    json->Append("\n" + indent + "}");
}

// Convert the tree to JSON format
String^ Tree::ToJSON() {
    StringBuilder^ json = gcnew StringBuilder();
    json->Append("{\n");
    json->Append("  \"root\": [\n");

    DepthFirstTraversal(root, json, 2);

    json->Append("\n  ]\n}");
    return json->ToString();
}

void JSONConverter::ConvertToJSON(System::IO::StreamReader^ input, String^ outputFileName) {
    System::IO::StreamWriter^ output = gcnew System::IO::StreamWriter(outputFileName);

    System::Xml::XmlDocument^ xmlDoc = gcnew System::Xml::XmlDocument();
    xmlDoc->Load(input);

    Tree^ tree = gcnew Tree("root"); // Initialize the tree with a root node
    ParseXMLNode(xmlDoc->DocumentElement, tree);

    output->WriteLine(tree->ToJSON());
    output->Close();
}

// Recursive function to parse XML nodes and build the tree structure
void JSONConverter::ParseXMLNode(System::Xml::XmlNode^ xmlNode, Tree^ tree) {
    tree->AddNode(xmlNode->Name);

    if (!String::IsNullOrEmpty(xmlNode->InnerText)) {
        tree->AddData(xmlNode->InnerText);
    }

    for each (System::Xml::XmlNode ^ childNode in xmlNode->ChildNodes) {
        ParseXMLNode(childNode, tree);
    }

    tree->MoveToParent();
}