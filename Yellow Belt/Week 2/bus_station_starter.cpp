#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    // Реализуйте эту функцию
    string operation_code;
    is >> operation_code >> operation_code;
    if (operation_code == "NEW_BUS")
    {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (int i=0;i<stop_count;i++) {
            cin >> q.stops[i];
        }
    }
    else if (operation_code == "BUSES_FOR_STOP")
    {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }
    else if (operation_code == "STOPS_FOR_BUS")
    {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    }
    else if (operation_code == "ALL_BUSES")
    {
        q.type = QueryType::AllBuses; 
    }
    return is;
}

struct BusesForStopResponse {
  // Наполните полями эту структуру
     vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    // Реализуйте эту функцию
    
    if (r.buses.size() != 0)
    {
        for(int i=0;i<r.buses.size();i++)
        {
            if(i < r.buses.size()-1)
            {
                os << r.buses[i] << " ";    
            }
            else
            {
                os << r.buses[i] << endl; 
            }
        }
    }
    else
    {
        os << "No stop" << endl;
    }

    return os;
}

struct StopsForBusResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    // Реализуйте эту функцию
    if (r.stops.size() != 0)
    {
        for(auto& stop : r.stops)
        {
            os << "Stop " << stop.first << ": ";
            
            if (stop.second.size() != 0)
            {
                for(auto& bus : stop.second)
                os << bus << " ";
            }
            else
            {
                os << "no interchange" << endl;
            }
            os << endl;
        }
    }
    return os;
}

struct AllBusesResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
    if (r.buses.size() != 0)
    {
        for(auto& bus : r.buses)
        {
            os << "Bus " << bus.first << ": ";
            for(auto& stop : bus.second)
            {
                os << stop << " ";
            }                
            os << endl;
        }
    }
    else
    {
        os << "No buses" << endl;
    }
    return os;
}

class BusManager {
public:
void AddBus(const string& bus, const vector<string>& stops) 
{
    // Реализуйте этот метод
    buses_to_stops[bus] = stops;
    
    for (const string& stop : stops) 
    {
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse GetBusesForStop(const string& stop) const 
{
    // Реализуйте этот метод
    return stops_to_buses.at(stop);
}

StopsForBusResponse GetStopsForBus(const string& bus) const 
{
    // Реализуйте этот метод  
    return buses_to_stops.at(bus);
}

AllBusesResponse GetAllBuses() const 
{
    // Реализуйте этот метод
    return buses_to_stops;
}
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
