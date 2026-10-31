#include <vector>
#include <utility>
#include <algorithm>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Short circuit on only 1 car case
        if(position.size() == 1) {
            return 1;
        }
        std::vector<std::pair<int, int>> pos_speed{}; // Constructing a tuple for position, speed
        for(std::size_t i{0}; i < position.size(); i++) {
            pos_speed.emplace_back(position[i], speed[i]); // emplace_back creates the tuple object
        }
        std::sort(pos_speed.begin(), pos_speed.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        }); // Since our positions are unique we don't need the comparator to check the second argument
        
        int num_fleets{1};

        // Keep track of fleet position and speed by using the leader of the fleet
        auto it = pos_speed.rbegin();   
        auto [fleet_position, fleet_speed] = *it;
        ++it;
        
        for (; it != pos_speed.rend(); ++it) {
            const auto& [curr_position, curr_speed] = *it;

            // Let x = time, y = distrance
            // If y_1 = fleet_speed * x + fleet_position
            /// y_2 = curr_speed * x + curr_position
            // x_intersect = y_1 = y_2 = (fleet_position - curr_position)/(curr_speed - fleet_speed)
            // y_intersect = y_1 @ x_intersect  = fleet_speed*x_intersect + fleet_position

            // Then check if the y_intersect (position intersect) is a valid domain of intersection,
            // which is (curr_pos, target]. If not, then the current car is part of a different fleet
            // and it becomes a new fleet leader

            // Short-circuit case if two cars have the same speed as positions are different (guarenteed
            // that positions are unique), then they don't intersect and x_intersect calculation would
            // be / 0. 
            if(curr_speed == fleet_speed) {
                num_fleets++;
                fleet_position = curr_position;
                fleet_speed = curr_speed;
                continue;
            }
            
            // x_intersect
            double time_intersection{static_cast<double>(fleet_position - curr_position)/(curr_speed - fleet_speed)};
            
            // y_intersect
            double position_intersection{fleet_speed*time_intersection + fleet_position};

            // Check if y_intersect is in domain of intersection, which is (curr_position, target]. 
            // If not the curr car is part of a new fleet as the fleet leader
            if(position_intersection > target || position_intersection <= curr_position) {
                num_fleets++;
                fleet_position = curr_position;
                fleet_speed = curr_speed;
            }
        }
        return num_fleets;
    }
};
