class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ret = "";
        if(numerator<0 ^ denominator<0) ret += "-";
        if(numerator==0) return "0";
        long nume, deno, t;
        nume = labs(numerator); 
        deno = labs(denominator);
        
        if(nume%deno==0){
            return ret + to_string(nume/deno);
        }
        ret += to_string(nume/deno) + ".";
        
        t = (nume%deno)*10;
        map<long,long> mm;
        while(t){
            long quotient = t/deno;
            if(mm.find(t)!=mm.end()){
                ret.insert(mm[t],1,'(');
                ret += ")";
                break;
            }
            mm[t] = ret.size();
            ret += to_string(quotient);
            t = (t%deno)*10;
        }
        return ret;
    }
};