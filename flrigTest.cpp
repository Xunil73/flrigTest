#include "flrigClient.h"

const std::string host {"127.0.0.1"};
const std::string port {"12345"};

using namespace std;

int main() {

  FlrigClient myClient(host, port);

  myClient.printAttr();

  double qrg[3] {14000000, 18069000, 145000000}; // 20m, 17m, 2m

  char inpt {'0'};
  while (inpt != 'q') {
    cout << "Frequenzwechsel:\n1. 20m\n2. 17m\n3. 2m\nbeenden mit 'q': ";
    cin >> inpt;
    switch(inpt) {
      case '1': myClient.setCurrentVfo(qrg[0]);
                break;
      case '2': myClient.setCurrentVfo(qrg[1]);
                break;
      case '3': myClient.setCurrentVfo(qrg[2]);
                break;
      default:  break;

    }
  }
}
