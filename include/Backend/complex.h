// COMPLEX -- all complex logic implementation
#ifndef COMPLEX
#define COMPLEX
#endif



class Complex {
public:
    using data_type = double;

    static const data_type c_re = 1;
    static const data_type c_im = 0;

    void process(
        data_type &res_re, data_type &res_im,
        data_type src_re,  data_type src_im
    );
};
