// COMPLEX -- all complex logic implementation
#ifndef COMPLEX
#define COMPLEX
#endif


class Complex {
public:
    using data_type = double;
    using iter_type = unsigned char;

    static void process(
        data_type &res_re, data_type &res_im,
        data_type prv_re,  data_type prv_im,
        data_type ini_re,  data_type ini_im
    ) noexcept;
};

Complex::data_type sq_abs(
    Complex::data_type re, Complex::data_type im
) noexcept;

Complex::iter_type belonging_rate(
    Complex::data_type ini_re, Complex::data_type ini_im
) noexcept;

