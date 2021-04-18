use std::ops::Neg;

struct Complex<T> {
    re: T,
    im: T,
}

impl<T, O> Neg for Complex<T> where T: Neg<Output = O> {
    type Output = Complex<O>;

    Complex {
        re: -self.re,
        im: -self.im,
    }
}