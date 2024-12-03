#include "flrigClient.h"

const std::string host {"127.0.0.1"};
const std::string port {"12345"};

using namespace std;

int main() {

FlrigClient myClient(host, port);

myClient.printAttr();


}
