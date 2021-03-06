#include "main.cpp"
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>
TEST(TestCase1, Solution) {
  auto Solve = [](std::istream &is) -> std::string {
    std::ostringstream oss;
    solve_uva_problem(is, oss);
    return std::string("\n") + oss.str();
  };
  {
    std::stringstream fake_cin;
    fake_cin
        << R"(2 6 5 10 10 4 10 10 10 4 5 10 4 5 10 9 7 6 1 7 6 9 5 3 10 10 4
			10  9 2   1 10 1 10 10 10 3 10 9 8 10 8 7 1 2 8 6 7 3 3 8 2
0
)";

    EXPECT_EQ(
        R"(
Win : 66
)",
        Solve(fake_cin));
  }
}

TEST(TestCase2, Solution) {
  auto Solve = [](std::istream &is) -> std::string {
    std::ostringstream oss;
    solve_uva_problem(is, oss);
    return std::string("\n") + oss.str();
  };
  {
    std::stringstream fake_cin;
    fake_cin
        << R"(2 6 5 10 10 4 10 10 10 4 5 10 4 5 10 9 7 6 1 7 6 9 5 3 10 10 4 10 9 2 1
10 1 10 10 10 3 10 9 8 10 8 7 1 2 8 6 7 3 3 8 2
4 3 2 10 8 10 6 8 9 5 8 10 5 3 5 4 6 9 9 1 7 6 3 5 10 10 8 10 9 10 10 7
2 6 10 10 4 10 1 3 10 1 1 10 2 2 10 4 10 7 7 10
10 5 4 3 5 7 10 8 2 3 9 10 8 4 5 1 7 6 7 2 6 9 10 2 3 10 3 4 4 9 10 1 1
10 5 10 10 1 8 10 7 8 10 6 10 10 10 9 6 2 10 10
0
)";

    EXPECT_EQ(
        R"(
Win : 66
Loss: 82
Draw: 73
)",
        Solve(fake_cin));
  }
}

#if 1
TEST(TestCase3, Solution)
{
	auto Solve = []() -> std::string {
		std::ifstream fs("./data1");
	    std::ostringstream oss;
		solve_uva_problem(fs,oss);
		return std::string("\n") + oss.str();
	};
	{
        EXPECT_EQ(
                R"(
Loss: 124
Loss: 127
Loss: 73
Loss: 241
Loss: 196
Loss: 250
Loss: 151
Loss: 142
Loss: 136
Loss: 109
Loss: 256
Loss: 346
Loss: 127
Loss: 244
Loss: 142
Loss: 106
Loss: 121
Loss: 169
Loss: 169
Loss: 211
Loss: 172
Loss: 235
Loss: 115
Loss: 172
Loss: 181
Loss: 121
Loss: 85
Loss: 145
Loss: 130
Loss: 139
Loss: 190
Loss: 196
Loss: 109
Loss: 103
Loss: 130
Loss: 148
Loss: 169
Loss: 88
Loss: 91
Loss: 103
Loss: 118
Loss: 385
Loss: 169
Loss: 256
Win : 390
Loss: 124
Loss: 88
Loss: 103
Loss: 85
Loss: 172
Loss: 109
Loss: 175
Loss: 175
Loss: 103
Loss: 133
Loss: 154
Loss: 268
Loss: 115
Loss: 151
Loss: 115
Loss: 139
Loss: 124
Loss: 133
Loss: 124
Loss: 205
Loss: 118
Loss: 160
Loss: 127
Loss: 85
Loss: 91
Loss: 82
Loss: 103
Loss: 136
Loss: 136
Loss: 103
Loss: 157
Loss: 127
Loss: 106
Loss: 169
Loss: 175
Loss: 73
Loss: 169
Loss: 106
Loss: 145
Loss: 79
Loss: 154
Loss: 175
Loss: 85
Loss: 142
Loss: 157
Loss: 166
Loss: 118
Loss: 112
Loss: 145
Win : 228
Loss: 64
Loss: 121
Loss: 124
Loss: 97
Loss: 124
Loss: 121
Loss: 157
Win : 153
Loss: 127
Loss: 166
Loss: 124
Loss: 88
Loss: 88
Loss: 100
Loss: 139
Loss: 277
Loss: 94
Loss: 256
Loss: 262
Loss: 520
Loss: 256
Loss: 97
Loss: 127
Loss: 154
Loss: 124
Loss: 133
Loss: 154
Loss: 133
Loss: 82
Loss: 133
Loss: 151
Loss: 88
Loss: 253
Loss: 130
Loss: 163
Loss: 97
Loss: 181
Loss: 85
Loss: 178
Loss: 166
Loss: 109
Loss: 88
Loss: 109
Loss: 106
Loss: 160
Loss: 127
Loss: 94
Loss: 133
Loss: 118
Loss: 124
Loss: 313
Loss: 79
Loss: 154
Loss: 148
Loss: 304
Loss: 82
Loss: 121
Loss: 136
Loss: 202
Loss: 214
Loss: 97
Loss: 118
Loss: 142
Loss: 121
Loss: 118
Loss: 199
Loss: 148
Loss: 166
Loss: 166
Win : 312
Loss: 97
Loss: 79
Loss: 106
Loss: 271
Loss: 106
Loss: 199
Loss: 106
Loss: 550
Loss: 130
Loss: 178
Loss: 205
Loss: 208
Loss: 115
Loss: 94
Loss: 100
Loss: 79
Loss: 244
Loss: 115
Loss: 187
Loss: 178
Loss: 121
Loss: 184
Loss: 103
Loss: 79
Loss: 193
Loss: 127
Loss: 76
Loss: 136
Loss: 118
Loss: 280
Loss: 292
Loss: 163
Loss: 85
Loss: 136
Loss: 196
Loss: 310
Loss: 310
Loss: 121
Loss: 172
Loss: 115
Loss: 121
Loss: 184
Loss: 118
Loss: 103
Loss: 148
Loss: 157
Loss: 199
Loss: 238
Draw: 142
Loss: 187
Loss: 148
Loss: 136
Loss: 88
Loss: 211
Loss: 196
Loss: 91
Loss: 106
Loss: 148
Loss: 148
Loss: 208
Loss: 109
Loss: 166
Loss: 124
Loss: 127
Loss: 175
Loss: 115
Loss: 175
Loss: 166
Loss: 109
Loss: 79
Loss: 205
Loss: 193
Loss: 100
Loss: 190
Loss: 88
Win : 246
Loss: 85
Loss: 109
Loss: 382
Loss: 115
Loss: 112
Loss: 136
Loss: 379
Loss: 139
Loss: 124
Loss: 136
Loss: 82
Loss: 148
Loss: 229
Loss: 136
Loss: 127
Loss: 196
Loss: 313
Loss: 106
Loss: 148
Loss: 322
Loss: 169
Loss: 142
Loss: 121
Loss: 175
Loss: 184
Loss: 175
Loss: 124
Loss: 151
Loss: 238
Loss: 163
Loss: 64
Loss: 595
Loss: 160
Loss: 151
Loss: 184
Loss: 133
Loss: 100
Loss: 91
Loss: 112
Loss: 157
Loss: 145
Loss: 94
Loss: 304
Loss: 142
Loss: 91
Loss: 148
Loss: 100
Loss: 133
Loss: 178
Loss: 112
Loss: 154
Loss: 118
Loss: 112
Loss: 172
Loss: 379
Loss: 121
Loss: 142
Loss: 112
Loss: 328
Loss: 160
Loss: 217
Loss: 187
Loss: 202
Loss: 145
Loss: 76
Loss: 190
Loss: 106
Loss: 145
Loss: 154
Loss: 85
Loss: 184
Loss: 355
Loss: 169
Loss: 289
Loss: 151
Loss: 79
Loss: 139
Loss: 184
Loss: 157
Loss: 130
Loss: 163
Loss: 403
Loss: 103
Loss: 184
Loss: 133
Loss: 136
Loss: 193
Loss: 232
Loss: 175
Loss: 289
Loss: 127
Loss: 124
Loss: 214
Loss: 121
Loss: 103
Loss: 562
Loss: 319
Loss: 64
Loss: 220
Loss: 148
Loss: 364
Win : 243
Loss: 187
Loss: 127
Loss: 85
Loss: 244
Loss: 205
Loss: 259
Loss: 169
Loss: 160
Loss: 97
Loss: 481
Loss: 142
Loss: 115
Loss: 169
Loss: 103
Loss: 100
Loss: 202
Loss: 121
Loss: 136
Loss: 115
Loss: 103
Loss: 148
Loss: 268
Loss: 190
Loss: 193
Loss: 118
Loss: 169
Loss: 94
Loss: 106
Loss: 214
Loss: 139
Loss: 118
Loss: 124
Loss: 91
Loss: 118
Loss: 79
Loss: 109
Loss: 163
Loss: 142
Loss: 109
Loss: 109
Loss: 109
Draw: 259
Loss: 169
Loss: 241
Loss: 166
Loss: 100
Loss: 112
Loss: 97
Loss: 118
Loss: 139
Loss: 85
Loss: 103
Loss: 115
Loss: 103
Loss: 193
Loss: 226
Loss: 139
)",
Solve());
    }
}
#endif
