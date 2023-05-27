#include <iostream>
#include <vector>

#define max_size 5

std::pair<int, int> one = std::make_pair(1, 0);
std::pair<int, int> two = std::make_pair(-1, 0);
std::pair<int, int> three = std::make_pair(0, 1);
std::pair<int, int> four = std::make_pair(0, -1);
std::vector<std::pair<int, int>> search = {one, two, three, four};
std::vector<std::pair<int, int>> memory;

struct Colors
{
    enum
    {
        black = 0,
        white = 1
    };
};

bool compute(std::vector<std::vector<int>> &map, std::pair<int, int> start, std::pair<int, int> &end, std::vector<std::pair<int, int>> &path, int &distance)
{
    // Can't go beyond the edge of the map
    if (start.first < 0 || start.first + 1 > max_size || start.second < 0 || start.second + 1 > max_size)
        return false;

    if (std::find(memory.begin(), memory.end(), start) != memory.end())
        return false;

    // Can't go through obstacles
    if (map[start.first][start.second] == Colors::black)
        return false;

    // Robot reached the end
    if (start.first == end.first && start.second == end.second)
    {
        // TODO: make use of this distance
        distance = 0;
        return true;
    }

    memory.push_back(start);

    // Perform depth first search on the map until reaching the location
    // This is greedy (for a comprehensive search compare the lengths of the paths)
    std::pair<int, int> new_start;
    for (int i = 0; i < search.size(); i++)
    {
        new_start.first = start.first + search[i].first;
        new_start.second = start.second + search[i].second;

        if (compute(map, new_start, end, path, distance))
        {
            path.push_back(new_start);
            distance++;
            return true;
        }
    }

    return false;
}

std::vector<std::vector<int>> createMap()
{
    std::vector<std::vector<int>> map;
    for (unsigned int i = 0; i < max_size; i++)
    {
        std::vector<int> temp_row;
        for (unsigned int j = 0; j < max_size; j++)
        {
            temp_row.push_back(Colors::white);
        }

        map.push_back((temp_row));
    }

    return map;
}

void populateObstacles(std::vector<std::vector<int>> &map)
{
    map[2][3] = Colors::black;
    map[3][3] = Colors::black;
    map[4][3] = Colors::black;
    map[2][4] = Colors::black;
    map[3][4] = Colors::black;
    map[4][4] = Colors::black;
}

int main(void)
{
    // input
    // 1. Map
    // 2. start,
    // 3. end

    // input 1.
    std::vector<std::vector<int>> map = createMap();
    // populateObstacles(map);

    std::pair<int, int> start = std::make_pair(2, 1);
    std::pair<int, int> end = std::make_pair(4, 4);

    // output
    // 1. path

    std::vector<std::pair<int, int>> path;
    int distance = 0;
    compute(map, start, end, path, distance);

    std::reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
    {
        std::cout << "the path is x:" << path[i].first << ", y:" << path[i].second << std::endl;
    }

    return 0;
}