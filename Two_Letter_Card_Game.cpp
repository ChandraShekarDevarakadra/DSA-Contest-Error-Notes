class Solution {
public:
    int score(vector<string>& cards, char x) {
        unordered_map<char,int> mp1,mp2;
        int bothX=0;
        for(int i=0;i<cards.size();i++){
            if(cards[i][0]==x&&cards[i][1]==x)bothX++;
            else if(cards[i][0]==x)mp1[cards[i][1]]++;
            else if(cards[i][1]==x)mp2[cards[i][0]]++;
        }
        priority_queue<int> q1,q2;
        for(auto i: mp1)q1.push(i.second);
        for(auto i: mp2)q2.push(i.second);
        int score=0;
        while(q1.size()>1){
            int num1=q1.top();q1.pop();
            int num2=q1.top();q1.pop();num1--;num2--;
            score++;
            if(num1>0)q1.push(num1);if(num2>0)q1.push(num2);
        }
        while(q2.size()>1){
            int num1=q2.top();q2.pop();
            int num2=q2.top();q2.pop();num1--;num2--;
            score++;
            if(num1>0)q2.push(num1);if(num2>0)q2.push(num2);
        }
        int ans1=score;
        int totalLeft=0;if(q1.size()>0)totalLeft+=q1.top();if(q2.size()>0)totalLeft+=q2.top();
        int num=min(bothX,totalLeft);
        ans1+=num;
        bothX-=num;
        if(bothX>0){
            ans1+=min(score,bothX/2);
        }
        return ans1;
    }
};