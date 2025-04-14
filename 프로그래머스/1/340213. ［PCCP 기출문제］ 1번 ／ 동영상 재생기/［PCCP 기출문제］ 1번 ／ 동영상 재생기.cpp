#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int toSeconds(string time);
string toTimeString(int seconds);

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string result;
    int ivideo_len = toSeconds(video_len);
    int ipos = toSeconds(pos);
    int iop_start = toSeconds(op_start);
    int iop_end = toSeconds(op_end);

    for (auto command : commands) {
        if (ipos >= iop_start && ipos <= iop_end) ipos = iop_end;

        if (command == "prev") ipos = max(0, ipos - 10);
        else if (command == "next") ipos = min(ivideo_len, ipos + 10);

        if (ipos >= iop_start && ipos <= iop_end) ipos = iop_end;
    }

    return toTimeString(ipos);
}

// "mm:ss" → 초 단위로 변환
int toSeconds(string time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

// 초 단위 → "mm:ss" 문자열로 변환
string toTimeString(int seconds) {
    int m = seconds / 60;
    int s = seconds % 60;
    char buf[6];
    sprintf(buf, "%02d:%02d", m, s);
    return string(buf);
}

/*
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int ivideo_len = 0, ipos = 0, iop_start = 0, iop_end = 0;
    string result = "00:00";
    for(int i = 0; i < 5; i++){
        if(i == 2) continue;
        ivideo_len = ivideo_len * 10 + (video_len[i] - '0');
        ipos = ipos * 10 + (pos[i] - '0');
        iop_start = iop_start * 10 + (op_start[i] - '0');
        iop_end = iop_end * 10 + (op_end[i] - '0');
    }
    
    for(auto command : commands) {
        if(ipos >= iop_start && ipos <= iop_end) ipos = iop_end;
        if(command == "prev") {
            ipos -= 10;
            if(ipos < 0) ipos = 0;
        }
        else if(command == "next") {
            ipos += 10;
            if(ipos > ivideo_len) ipos = ivideo_len;
        }
        if(ipos % 100 >= 60) ipos += 40;
        if(ipos >= iop_start && ipos <= iop_end) ipos = iop_end;
    }
    
    for(int i = 4; i >= 0; i--) {
        if(i == 2) continue;
        if(ipos == 0) {
            result[i] = '0';
            ipos /= 10;
            continue;
        }
        result[i] = (ipos % 10) + '0';
        ipos /= 10;
    }
    
    return result;
}
*/