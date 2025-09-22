// 폰켓몬

#include <vector>
#include <unordered_map>
using namespace std;


int solution(vector<int> nums)
{   
    int answer = 0;
    unordered_map<int, int> pokemonHash;

    for (int i = 0; i < nums.size(); i++) {
        // 새로운 종류의 포켓몬이면 map에 추가
        if (pokemonHash.find(nums[i]) == pokemonHash.end()) {
            pokemonHash.insert({nums[i], 1});
        }
    }

    int tryNum = nums.size() / 2;

    // pokemon 종류가 뽑으려고 하는 개수 이상이면 anwer = 뽑으려고 하는 개수
    if (pokemonHash.size() >= tryNum) {
        answer = tryNum;
    }
    // pokemon 종류가 뽑으려고 하는 개수 미만이면 answer = pokemon 종류 총 개수
    else if (pokemonHash.size() < tryNum){
        answer = pokemonHash.size();
    }

    return answer;
}
