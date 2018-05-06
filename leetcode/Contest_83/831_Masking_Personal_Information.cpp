class Solution
{
public:
    string maskPII(string S)
    {
        if (isalpha(S[0])) { // email
            int pos = S.find("@");
            for (int i = 0; i < S.length(); i++) {
                S[i] = tolower(S[i]);
            }
            string ns = "";
            ns.assign(1, S[0]);
            ns += "*****";
            ns += S.substr(pos - 1, S.length() - pos + 1);
            // cout << ns << endl;
            return ns;
        } else { // phone
            string ns = "";
            for (int i = 0; i < S.length(); i++) {
                if (isdigit(S[i])) {
                    ns.push_back(S[i]);
                }
            }
            cout << ns << endl;
            if (ns.length() == 10) {
                string nns = "***-***-";
                nns += ns.substr(6, 4);
                return nns;
            } else {
                string nns = "+";
                for (int i = 0; i < ns.length() - 10; i++) {
                    nns.push_back('*');
                }
                nns += "-***-***-";
                nns += ns.substr(ns.length() - 4, 4);
                return nns;
            }
        }
    }
};
