#include <iostream>
#include <cassert>
#include <string>
#include <map>
#include <vector>
using namespace std;
using BusesAndStops = map<string, vector<string>>;
class BusManager { ;
private:
    BusesAndStops buses_to_stops,stops_to_buses;
public:
    void AddBus(string &bus_name) {
        int stop_count;
        cin >> stop_count;
        vector<string>& stops = buses_to_stops[bus_name];//создаем пару обращаясь к ключу
        stops.resize(stop_count);
        for (string &stop : stops) {
            cin >> stop;
            stops_to_buses[stop].push_back(bus_name);
        }
    }
    void PrintStopToBuses(string &stop_name) {
        if (stops_to_buses.count(stop_name) == 0) {
            cout << "No stop like this" << endl;
        } else {
            for (const string &bus : stops_to_buses[stop_name]) {
                cout << bus << " ";
            }
            cout << endl;
        }
    }

    void PrintBusToStops(string &bus_name) {
        if (buses_to_stops.count(bus_name) == 0) {
            cout << "No bus" << endl;
        } else {
            for (const string &stop : buses_to_stops[bus_name]) {//итерация по вектору остановокнашего автобуса
                cout << "Stop " << stop << ": ";
                if (stops_to_buses[stop].size() == 1) {
                    cout << "no interchange";
                } else {
                    for (const string &other_bus : stops_to_buses[stop]) {
                        if (bus_name != other_bus) {
                            cout << other_bus << " ";
                        }
                    }
                }
                cout << endl;
            }
        }
    }

    void PrintAll() {
        if (buses_to_stops.empty()) {
            cout << "No buses" << endl;
        } else {
            for (const auto &bus_item : buses_to_stops) {
                cout << "Bus " << bus_item.first << ": ";
                for (const string &stop : bus_item.second) {
                    cout << stop << " ";
                }
                cout << endl;
            }
        }
    }
};
int main() {
    int q;
    cin >> q;
    BusManager new_union;
    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;
        if (operation_code == "NEW_BUS") {

            string bus_name;
            cin >> bus_name;
            new_union.AddBus(bus_name);

        } else if (operation_code == "BUSES_FOR_STOP") {

            string stop;
            cin >> stop;
            new_union.PrintBusToStops(stop);

        } else if (operation_code == "STOPS_FOR_BUS") {

            string bus;
            cin >> bus;
            new_union.PrintStopToBuses(bus);

        } else if (operation_code == "ALL_BUSES") {
            new_union.PrintAll();
        }
    return 0;
}
