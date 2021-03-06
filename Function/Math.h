#include "../Function/QuickCard.h"
#include "../Model/STACK.h"

using namespace std;
#ifndef MAIN_CPP_MATH_H
#define MAIN_CPP_MATH_H


//Call all Math Algorithm in and inherent all function and data from Stack.
class Math : public STACK {
public:
    virtual ~Math();

    template<typename M>
    static void mean(M *mean_x, M *mean_y);

    template<typename ME>
    static void median(ME *median_x, ME *median_y);

    template<typename F>
    static void mode(F *mode_x, F *mode_y);

    template<typename V>
    static void variance(V *var_x, V *var_y);

    template<typename Ma>
    static void mad(Ma *mad_x, Ma *mad_y);

    template<typename Th>
    static void ThirdQuartile(Th *Q3_x, Th *Q3_y);

    template<typename Sk>
    static void Skewness(Sk *Sk_x, Sk *Sk_y);

    template<typename Ku>
    static void kurtosis(Ku *Ku_x, Ku *Ku_y);

    template<typename Co>
    static void covariance(Co *Co_x_y);

    template<typename Ce>
    static void Coefficient(Ce *Coefficient_x_y);

    template<typename Re>
    static void Regression_a(Re *re_a);

    template<typename ReB>
    static void Regression_b(ReB *re_b);

    static void Start_Algorithm();
};

//Struct to capacity of all value.
static struct math_struct {
    double mean_x = 0, mean_y = 0, median_x = 0, median_y = 0, mode_x = 0, mode_y = 0,
            var_x = 0, var_y = 0, mad_x = 0, mad_y = 0, Q3_x = 0, Q3_y = 0, Sk_x = 0, Sk_y = 0,
            Ku_x = 0, Ku_y = 0, Co_x_y = 0, Coefficient_x_y = 0, re_a = 0, re_b = 0;
} mt;

//IN this File of code I use template because while
// i change to float or int it will be fast and friendly to look

//Function to calculate Mean
template<typename M>
void Math::mean(M *mean_x, M *mean_y) {
    double sum_x = 0;
    for (int i = 0; i < st.top + 1; i++) {
        sum_x += st.data_x[i];
    }
    *mean_x = sum_x / (st.top + 1);
    double sum_y = 0;
    for (int j = 0; j < st.top + 1; j++) {
        sum_y += st.data_y[j];
    }
    *mean_y = sum_y / (st.top + 1);
}


//Function to calculate median
template<typename ME>
void Math::median(ME *median_x, ME *median_y) {
    int flag = (st.top + 1) % 2;
    if (flag != 0) {
        *median_x = st.data_x[((st.top / 2))];
        *median_y = st.data_y[((st.top / 2))];
    } else {
        *median_x = ((st.data_x[(st.top - 1) / 2] + st.data_x[((st.top - 1) / 2) + 1]) / 2);
        *median_y = ((st.data_y[(st.top - 1) / 2] + st.data_y[((st.top - 1) / 2) + 1]) / 2);
    }
}

//Function to calculate mode this line of code take a lot of time but i don't know how to code it better
template<typename F>
void Math::mode(F *mode_x, F *mode_y) {
    int maxCount_x = 0, maxCount_y = 0;
    for (int i = 0; i < st.top + 1; ++i) {
        int count_x = 0;
        int count_y = 0;
        for (int j = 0; j < st.top + 1; ++j) {
            if (st.data_x[j] == st.data_x[i])
                ++count_x;
            if (st.data_y[j] == st.data_y[i])
                ++count_y;
        }

        if (count_x > maxCount_x) {
            maxCount_x = count_x;
            *mode_x = st.data_x[i];
        } else if (count_y > maxCount_y) {
            maxCount_y = count_y;
            *mode_y = st.data_y[i];
        }
    }
}


//Function to calculate Variance
template<typename V>
void Math::variance(V *var_x, V *var_y) {
    double dev_x = 0.0, dev_y = 0.0;
    for (int i = 0; i < st.top + 1; i++) {
        dev_x += pow((st.data_x[i] - mt.mean_x), 2);
        dev_y += pow((st.data_y[i] - mt.mean_y), 2);
    }
    *var_x = dev_x / (st.top);
    *var_y = dev_y / (st.top);
}


//Function to calculate Mad
template<typename Ma>
void Math::mad(Ma *mad_x, Ma *mad_y) {
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < st.top + 1; i++) {
        sum_x += abs(st.data_x[i] - mt.mean_x);
        sum_y += abs(st.data_y[i] - mt.mean_y);
    }
    *mad_x = sum_x / (st.top + 1);
    *mad_y = sum_y / (st.top + 1);
}

//Function To calculate Q3
template<typename Th>
void Math::ThirdQuartile(Th *Q3_x, Th *Q3_y) {
    int flag = (st.top + 1) % 2;
    int flag1 = ((st.top + 1) / 2) % 2;
    if (flag != 0) {
        if (flag1 != 0) {
            *Q3_x = st.data_x[((st.top + 2) * 3 / 4) - 1];
            *Q3_y = st.data_y[((st.top + 2) * 3 / 4) - 1];
        } else {
            *Q3_x = (st.data_x[((st.top) * 3 / 4)] + st.data_x[((st.top) * 3 / 4) + 1]) / 2;
            *Q3_y = (st.data_y[((st.top) * 3 / 4)] + st.data_y[((st.top) * 3 / 4) + 1]) / 2;
        }
    } else {
        if (flag1 != 0) {
            *Q3_x = st.data_x[((st.top + 3) * 3 / 4) - 2];
            *Q3_y = st.data_y[((st.top + 3) * 3 / 4) - 2];
        } else {
            *Q3_x = (st.data_x[((st.top + 1) * 3 / 4) - 1] + st.data_x[((st.top + 1) * 3 / 4)]) / 2;
            *Q3_y = (st.data_y[((st.top + 1) * 3 / 4) - 1] + st.data_y[((st.top + 1) * 3 / 4)]) / 2;
        }
    }
}


//Function to calculate Skewness
template<typename Sk>
void Math::Skewness(Sk *Sk_x, Sk *Sk_y) {
    Sk sum_x = 0, sum_y = 0, s_x = sqrt(mt.var_x), s_y = sqrt(mt.var_y);
    for (int i = 0; i < st.top + 1; i++) {
        sum_x += pow((st.data_x[i] - mt.mean_x) / s_x, 3);
        sum_y += pow((st.data_y[i] - mt.mean_y) / s_y, 3);
    }
    *Sk_x = sum_x / st.top;
    *Sk_y = sum_y / st.top;
}

//Function to calculate kurtosis
template<typename Ku>
void Math::kurtosis(Ku *Ku_x, Ku *Ku_y) {
    double m4_x = 0, m4_y = 0;
    double s_x = sqrt(mt.var_x);
    double s_y = sqrt(mt.var_y);
    for (int i = 0; i < st.top + 1; i++) {
        m4_x += pow((st.data_x[i] - mt.mean_x) / s_x, 4);
        m4_y += pow((st.data_y[i] - mt.mean_y) / s_y, 4);
    }
    *Ku_x = (m4_x / (st.top + 1)) - 3;
    *Ku_y = (m4_y / (st.top + 1)) - 3;
}

//Function to calculate Covariance
template<typename Co>
void Math::covariance(Co *Co_x_y) {
    Co sum = 0;
    for (int i = 0; i < st.top + 1; i++) {
        sum += ((st.data_x[i] - mt.mean_x) * (st.data_y[i] - mt.mean_y));
    }
    *Co_x_y = sum / (st.top);
}

//Function to calculate Coefficient
template<typename Ce>
void Math::Coefficient(Ce *Coefficient_x_y) {
    Ce sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;
    for (int i = 0; i < st.top + 1; i++) {
        sumX += st.data_x[i];
        sumY += st.data_y[i];
        sumXY += (st.data_x[i] * st.data_y[i]);
        sumX2 += (st.data_x[i] * st.data_x[i]);
        sumY2 += (st.data_y[i] * st.data_y[i]);
    }
    *Coefficient_x_y = ((st.top + 1) * sumXY - sumX * sumY)
                       / sqrt(((st.top + 1) * sumX2 - sumX * sumX) * ((st.top + 1) * sumY2 - sumY * sumY));
}

//Function to calculate Regression value of a
template<typename Re>
void Math::Regression_a(Re *re_a) {
    *re_a = (mt.Coefficient_x_y * sqrt(mt.var_y)) / sqrt(mt.var_x);
}

//Function to calculate Regression value of b
template<typename ReB>
void Math::Regression_b(ReB *re_b) {
    *re_b = mt.mean_y - (mt.re_a * mt.mean_x);
}

void Math::Start_Algorithm() {
    mean<double>(&mt.mean_x, &mt.mean_y);
    mode<double>(&mt.mode_x, &mt.mode_y);
    median<double>(&mt.median_x, &mt.median_y);
    variance<double>(&mt.var_x, &mt.var_y);
    mad<double>(&mt.mad_x, &mt.mad_y);
    ThirdQuartile<double>(&mt.Q3_x, &mt.Q3_y);
    Skewness<double>(&mt.Sk_x, &mt.Sk_y);
    kurtosis<double>(&mt.Ku_x, &mt.Ku_y);
    covariance<double>(&mt.Co_x_y);
    Coefficient<double>(&mt.Coefficient_x_y);
    Regression_a<double>(&mt.re_a);
    Regression_b<double>(&mt.re_b);
}


//destruction while it done
Math::~Math() = default;


#endif //MAIN_CPP_MATH_H