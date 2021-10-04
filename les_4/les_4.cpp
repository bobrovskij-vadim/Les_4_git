#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>

//1.  Имеется отсортированный массив целых чисел.Необходимо разработать функцию insert_sorted, 
//    которая принимает вектор и новое число и вставляет новое число в определенную позицию в векторе, 
//    чтобы упорядоченность контейнера сохранялась.Реализуйте шаблонную функцию insert_sorted, 
//    которая сможет аналогично работать с любым контейнером, содержащим любой тип значения.
//2.  Сгенерируйте вектор, состоящий из 100 вещественный чисел, представляющий собой значения аналогового сигнала, 
//    изменяющегося по синусоиде.На основе этого массива чисел создайте другой вектор целых чисел, 
//    представляющий цифровой сигнал, в котором будут откинуты дробные части чисел.Выведите получившиеся массивы чисел.
//    Посчитайте ошибку, которой обладает цифровой сигнал по сравнению с аналоговым по формуле : 
//    .Постарайтесь воспользоваться алгоритмическими функциями, не используя циклы.

template<typename T>

void insert_sorted(std::vector<T>& vec , T num)
{
    std::vector<int> vec_2, vec_3;

    for (auto i : vec)
    {
        if (i < num) {
            vec_2.push_back(i);
        }
        else if (i >= num)
        {
            vec_3.push_back(i);
        }
    }
    vec_2.push_back(num);

    vec_2.insert(vec_2.end(), std::make_move_iterator(vec_3.begin()), std::make_move_iterator(vec_3.end()));

    std::cout << std::endl;

    std::copy(vec_2.begin(), vec_2.end(), std::ostream_iterator<int>(std::cout, " "));
}


int main()
{

    //---------------Ex_1---------------
    std::cout << "---------------Ex_1---------------" << std::endl;
    std::vector<int> vec(10);

    std::generate(vec.begin(), vec.end(), []() {return (rand() % 100); });

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;

    sort(vec.begin(), vec.end());

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;

    int n = 48;

    insert_sorted(vec, n);

    //---------------Ex_2---------------
    std::cout << "\n\n---------------Ex_2---------------" << std::endl;
   
    std::vector<float> analog(100);
   
    std::generate(analog.begin(), analog.end(), []() {return (float(rand())/float(RAND_MAX)*5.0); });
    std::copy(analog.begin(), analog.end(), std::ostream_iterator<float>(std::cout, " "));

    std::cout << "\n" << std::endl;

    std::vector<int> digit(analog.begin(), analog.end());
    std::copy(digit.begin(), digit.end(), std::ostream_iterator<int>(std::cout, " "));

    //Придумал только такой вариант, но он не правильно считает 

    float res = pow((std::accumulate(analog.begin(), analog.end(), decltype(analog)::value_type(0))) - (std::accumulate(digit.begin(), digit.end(), decltype(digit)::value_type(0))), 2);

    std::cout << "\n " << res << std::endl;
  

    float sum = 0;

    for (int i = 0; i < analog.size(); ++i)
    {
        sum += pow(analog[i] - digit[i], 2);
    }

    std::cout << "\n" << sum << std::endl;

    return 0;
}

