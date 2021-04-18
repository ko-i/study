use std::ops::Add;

#[derive(Debug)]
struct Complex<T> {
    re: T,
    im: T,
}

impl<T> Add for Complex<T> where T: Add<Output = T> {
    type Output = Self;

    fn add(self, rhs: Self) -> Self {
        Complex {
            re: self.re + rhs.re,
            im: self.im + rhs.im,
        }
    }
}

fn main() {
    let com_int1 = Complex::<i32> {
        re: 1,
        im: 1,
    };

    let com_int2 = Complex::<i32> {
        re: 2,
        im: 2,
    };

    println!("{:?}", com_int1 + com_int2);
}