use std::cmp::PartialEq;

struct Complex<T> {
    re: T,
    im: T,
}

impl<T: PartialEq> PartialEq for Complex<T> {
    fn eq(&self, other: &Complex<T>) -> bool {
        self.re == other.re && self.im == other.im
    }
}