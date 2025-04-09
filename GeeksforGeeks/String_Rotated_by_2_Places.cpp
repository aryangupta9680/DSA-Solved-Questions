class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.

    void rotateclockwise(string &s)
    {
        char c = s[0];
        int index = 1;

        while (index < s.size())
        {
            s[index - 1] = s[index];
            index++;
        }

        s[s.size() - 1] = c;
    }

    void rotateanticlockwise(string &s)
    {
        char c = s[s.size() - 1];
        int index = s.size() - 2;

        while (index >= 0)
        {
            s[index + 1] = s[index];
            index--;
        }

        s[0] = c;
    }

    bool isRotated(string &s1, string &s2)
    {
        if (s1.size() != s2.size())
        {
            return 0;
        }

        string clockwise, anticlockwise;

        clockwise = s1;
        rotateclockwise(clockwise);
        rotateclockwise(clockwise);

        if (clockwise == s2)
        {
            return 1;
        }

        anticlockwise = s1;
        rotateanticlockwise(anticlockwise);
        rotateanticlockwise(anticlockwise);

        if (anticlockwise == s2)
        {
            return 1;
        }

        return 0;
    }
};