// Binary Watch


class Solution {
public:
vector<int>hours = {1,2,4,8};
vector<int>mins = {1,2,4,8,16,32};
  void helper(vector<string>&res,pair<int,int>time,int No_Of_LEDs,int idx)
    {
        // agar number of LEDs zero hojaate hai iska matlab mujhe ek possible time milgaya jisse mein apne result vector mein add karlunga
        if(No_Of_LEDs==0)
        {
            // agar number of minutes less than 10 hai toh ":0" ko add karenge like this : "12:05"
            if(time.second<10)
            {
                res.push_back(to_string(time.first)+":0"+to_string(time.second));
            }
            // agar number of minutes greater than 10 hai toh ":" ko add karenge like this : "12:15"
            else
            {
                res.push_back(to_string(time.first)+":"+to_string(time.second));
            }
            return;
        }
        int n = hours.size();
        int m = mins.size();
        for(int i=idx;i<(m+n);i++)
        {
            // agar saare 6 LEDs hours waale check nahi kare abhi toh pehle unhe check karo
            if(i<n)
            {
                // current hour waale LED ko lelo
                time.first += hours[i];
                // agar hours less than 12 hai toh aage bado
                if(time.first<12)
                {
                    helper(res,time,No_Of_LEDs-1,i+1);
                }
                // backtracking step current hour jo liya tha usse remove karo taaki kisi aur hour waale LED ko use kar saken
                time.first -= hours[i];
            }
            // agar saare 6 LEDs hours waale check karliye toh ab minutes waale LEDs ko check karo
            else
            {
                // current minutes waale LED ko lelo
                time.second += mins[i-n];
                // agar minutes less than 60 hai toh aage bado
                if(time.second<60)
                {
                    helper(res,time,No_Of_LEDs-1,i+1);
                }
                // backtracking step current minutes jo liya tha usse remove karo taaki kisi aur minutes waale LED ko use kar saken
                time.second -= mins[i-n];
            }
        }
    }
   vector<string> readBinaryWatch(int turnedOn) {
        // ek vector of string le lenge return karne ke liye
        vector<string>res;
        // helper function ko call karenge
        helper(res,{0,0},turnedOn,0);
        return res;
    }
};
