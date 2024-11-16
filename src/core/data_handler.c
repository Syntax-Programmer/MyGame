// #include <libxml/parser.h>
// #include <libxml/tree.h>
// #include <stdio.h>

// void print_element_names_and_attributes(xmlNode *node)
// {
//     for (xmlNode *cur_node = node; cur_node; cur_node = cur_node->next)
//     {
//         if (cur_node->type == XML_ELEMENT_NODE)
//         {
//             printf("Element: %s\n", cur_node->name);

//             // Print attributes if any
//             for (xmlAttr *attr = cur_node->properties; attr; attr = attr->next)
//             {
//                 xmlChar *value = xmlNodeListGetString(cur_node->doc, attr->children, 1);
//                 printf("  Attribute: %s = %s\n", attr->name, value);
//                 xmlFree(value);
//             }
//         }
//         // Recurse into child nodes
//         print_element_names_and_attributes(cur_node->children);
//     }
// }

// int main()
// {
//     LIBXML_TEST_VERSION

//     // Parse the XML file
//     xmlDoc *doc = xmlReadFile("example.xml", NULL, 0);
//     if (doc == NULL)
//     {
//         printf("Error: Could not parse XML file.\n");
//         return -1;
//     }

//     // Get the root element
//     xmlNode *root_element = xmlDocGetRootElement(doc);

//     // Print root element
//     printf("Root element: %s\n", root_element->name);

//     // Print child elements and attributes
//     print_element_names_and_attributes(root_element->children);

//     // Cleanup
//     xmlFreeDoc(doc);
//     xmlCleanupParser();

//     return 0;
// }
