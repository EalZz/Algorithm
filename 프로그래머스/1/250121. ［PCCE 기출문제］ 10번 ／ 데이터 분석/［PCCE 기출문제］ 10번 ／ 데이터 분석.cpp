#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    for(auto d : data) {
        if (ext == "code") {
            if(d[0] < val_ext) answer.push_back(d);
        } 
        else if (ext == "date") {
            if(d[1] < val_ext) answer.push_back(d);
        } 
        else if (ext == "maximum") {
            if(d[2] < val_ext) answer.push_back(d);
        } 
        else if (ext == "remain") {
            if(d[3] < val_ext) answer.push_back(d);
        }
    }
    sort(answer.begin(), answer.end(), [sort_by](vector<int> v1, vector<int> v2){
        if (sort_by == "code") return v1[0] < v2[0];
        else if (sort_by == "date") return v1[1] < v2[1];
        else if (sort_by == "maximum") return v1[2] < v2[2];
        else if (sort_by == "remain") return v1[3] < v2[3];
    });
        
    return answer;
}