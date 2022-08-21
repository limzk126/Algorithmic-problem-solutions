class Solution {
    public:
        int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
            int n = energy.size();
            int en = initialEnergy;
            int ex = initialExperience;

            int training = 0;
            for (int i = 0; i < n; ++i) {
                if (ex <= experience[i]) {
                    training += experience[i] - ex + 1;
                    ex = experience[i] + 1;
                }
                if (en <= energy[i]) {
                    training += energy[i] - en + 1;
                    en = energy[i] + 1;
                }

                en -= energy[i];
                ex += experience[i]; 
            }

            return training; 
        }
};
