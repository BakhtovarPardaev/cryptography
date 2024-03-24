#include <iostream>
#include <bitset>


class A5Cipher {
private:
    std::bitset<19> R1, R2, R3;

    void shift(std::bitset<19>& reg, int feedback) {
        reg >>= 1;
        reg[18] = feedback;
    }

    int majority(int x, int y, int z) {
        return (x & y) ^ (x & z) ^ (y & z);
    }

public:
    A5Cipher(std::bitset<64> key) {
        for (int i = 0; i < 64; ++i) {
            int feedback = (key[i] + R1[8] + R2[10] + R3[10]) % 2;
            if (i < 19)
                R1[i] = key[i];
            if (i < 22)
                R2[i] = key[i];
            if (i < 23)
                R3[i] = key[i];
            shift(R1, feedback);
            if (i % 2 == 0)
                shift(R2, feedback);
            if (i % 3 == 0)
                shift(R3, feedback);
        }
    }


    std::bitset<64> encrypt(std::bitset<64> plaintext) {
        std::bitset<64> ciphertext;
        for (int i = 0; i < 64; ++i) {
            int maj = majority(R1[8], R2[10], R3[10]);
            int key = R1[18] ^ maj;
            ciphertext[i] = plaintext[i] ^ key;

            int feedback = (plaintext[i] + R1[8] + R2[10] + R3[10]) % 2;
            shift(R1, feedback);
            if (i % 2 == 0)
                shift(R2, feedback);
            if (i % 3 == 0)
                shift(R3, feedback);
        }
        return ciphertext;
    }
};
