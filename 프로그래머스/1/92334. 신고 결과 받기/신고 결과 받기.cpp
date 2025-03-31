#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> result (id_list.size(), 0);
    vector<int> cntp(id_list.size());
    vector<string> ban;
    
    //중복제거(신고자와 피신고자가 같으면 집계되지 않음)
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    //report를 공백 기준으로 구분해 2차원 벡터로 reports에 저장
    vector<vector<string>> reports;
    for(int i = 0; i < report.size(); i++) {
        vector<string> names;
        stringstream ss(report[i]);
        string name;
        
        while (ss >> name) names.push_back(name);
        reports.push_back(names);
    }
    
    //신고 횟수 집계
    for(int i = 0; i < reports.size(); i++) {
        auto itp = find(id_list.begin(), id_list.end(), reports[i][1]); 
        if (itp != id_list.end()) { 
            int index = distance(id_list.begin(), itp); 
            cntp[index]++;
        }
    }
    
    //정지된 사람 리스트
    for(int i = 0; i < cntp.size(); i++) {
        if (cntp[i] >= k) ban.push_back(id_list[i]);
    }
    
    //유효 신고자 저장
    vector<string> filtered_reporters;
    for (const auto& reported : reports) {
        for (const auto& banned : ban) {
            if (reported[1] == banned) { 
                filtered_reporters.push_back(reported[0]); 
                break; 
            }
        }
    }
    
    //메일 수 체크
    for (int i = 0; i < id_list.size(); i++) {
        for (const auto& reporter : filtered_reporters) {
            if (id_list[i] == reporter) result[i]++; 
        }
    }

    return result;
}