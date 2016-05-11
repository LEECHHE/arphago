/* 문제를 푸실 때, 아래 "화학원소 기호"를 활용하시기 바랍니다.
 "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
 "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
 "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
 "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
 "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
 "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
 "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
 "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
 "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
 "No", "Lr"   */

// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
string element[] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
    "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
    "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
    "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
    "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
    "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
    "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
    "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
    "No", "Lr"
};
bool dict[26][27];
bool can_start[26] = { false };
void make_dictionary(){
    for( int i = 0 ; i < 114 ; ++i ){
        if( element[i].length() == 1 ){
            dict[element[i][0]-'A'][26] = true;
        }
        else{
            dict[element[i][0]-'A'][element[i][1]-'a'] = true;
        }
        can_start[element[i][0]-'A'] = true;
    }
}
char word[50005];
int dp[50005];
long len;
bool solve(int idx){
    if( idx == len ) return true;
    int& ret = dp[idx];
    if( ret != -1 ) return ret;
    int s = word[idx]-'a';
    if( !can_start[s] ) return false;
    ret = false;
    if( dict[s][26] ) ret = solve(idx+1);
    if( !ret && idx < len-1 && dict[s][word[idx+1]-'a']){
        ret = solve(idx+2);
    }
    return ret;
}
int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    int TC;
    int test_case;
    scanf("%d", &TC);	// cin 사용 가능
    
    make_dictionary();
    for(test_case = 1; test_case <= TC; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오.
        scanf("%s",word);
        len = strlen(word);
        memset(dp,-1,sizeof(dp));
        
        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);	// cout 사용 가능
        printf("%s\n", solve(0)?"YES":"NO");
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}