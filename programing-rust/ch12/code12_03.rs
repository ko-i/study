use std::ops::AddAssign;

struct Complex<T> {
    re: T,
    im: T,
}

impl<T> AddAssign for Complex<T> where T: AddAssign<T> {
    fn add_assign(&mut self, rhs: Complex<T>) {
        self.re += rhs.re;
        self.im += rhs.im;
    }
}