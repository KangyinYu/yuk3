#include "Customer.h"
#include "tinystr.h"
#include "tinyxml.h"
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<iomanip>

using namespace std;
static const int NUM_OF_CUSTOMER = 51;
static const char* FILENAME = "RC101_050.xml";

int main(){
    vector<Customer *> customerSet(0);
    int i,j,k,count;
    int temp1;
    float temp2;
    Customer* customer;
    for (i=0; i<NUM_OF_CUSTOMER; i++) {
        customer = new Customer();
        customerSet.push_back(customer);
    }
    TiXmlDocument doc(FILENAME);
    if(!doc.LoadFile()) return -1;
    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    pElem = hDoc.FirstChildElement().Element();
    TiXmlHandle hRoot(pElem);


    TiXmlElement* nodeElem = hRoot.FirstChild("network").FirstChild("nodes").FirstChild("node").Element(); 
    count = 0;
    for(nodeElem; nodeElem; nodeElem = nodeElem->NextSiblingElement()) {
        customer = customerSet[count];
        TiXmlHandle node(nodeElem);
        TiXmlElement* xElem = node.FirstChild("cx").Element();
        TiXmlElement* yElem = node.FirstChild("cy").Element();
        nodeElem->QueryIntAttribute("id", &temp1);
        customer->setId(temp1);
        temp2 = atof(xElem->GetText());
        customer->setX(temp2);
        temp2 = atof(yElem->GetText());
        customer->setY(temp2);
        count++;
    }


    TiXmlElement* requestElem = hRoot.FirstChild("requests").FirstChild("request").Element();
    count = 1;
    for(requestElem; requestElem; requestElem = requestElem->NextSiblingElement()) {
        customer = customerSet[count];
        TiXmlHandle request(requestElem);
        TiXmlElement* startTimeElem = request.FirstChild("tw").FirstChild("start").Element();
        TiXmlElement* endTimeElem = request.FirstChild("tw").FirstChild("end").Element();
        TiXmlElement* quantityElem = request.FirstChild("quantity").Element();
        TiXmlElement* serviceTimeElem = request.FirstChild("service_time").Element();

        temp2 = atof(startTimeElem->GetText());
        customer->setStartTime(temp2);
        temp2 = atof(endTimeElem->GetText());
        customer->setEndTime(temp2);
        temp2 = atof(quantityElem->GetText());
        customer->setQuantity(temp2);
        temp2 = atof(serviceTimeElem->GetText());
        customer->setServiceTime(temp2);
        count++;
    }


    cout<<setiosflags(ios_base::left)<<setw(6)<<"id"<<setw(6)<<"x"<<setw(6)<<
        "y"<<setw(12)<<"startTime"<<setw(12)<<"endTime"<<setw(12)<<"quantity"<<setw(14)<<"serviceTime"<<endl;
    for(i=0; i<NUM_OF_CUSTOMER; i++) {
        customer = customerSet[i];
        customer->show();
    }
    system("pause");
    return 0;
}
