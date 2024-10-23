#include <iostream>

// BigInt([1|2]) -> 12
// BigInt([0|2]) -> 2
class BigInt
{
public:
    BigInt() = default;

    BigInt(int num[2]) {
        num_[0] = num[1];
        num_[1] = num[0];
    }

    bool operator==(const BigInt& rhs)
    {
        return num_[0] == rhs.num_[0] && num_[1] == rhs.num_[1];
    }

    bool operator!=(const BigInt& rhs)
    {
        return !(*this == rhs);
    }

    BigInt operator+(const BigInt& rhs)
    {
        BigInt res;
        int k = (num_[0] + rhs.num_[0]) / 10;
        int r = (num_[0] + rhs.num_[0]) % 10;
        res.num_[0] = r;
        res.num_[1] = k + num_[1] + rhs.num_[1];
        return res;
    }

    friend std::ostream& operator<<(std::ostream& out, const BigInt& rhs);

private:
    int32_t num_[2];
};

std::ostream& operator<<(std::ostream& out, const BigInt& rhs)
{
    out << rhs.num_[1] << rhs.num_[0];
    return out;
}
