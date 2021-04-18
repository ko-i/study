pub trait Add<RHS = Self> {
    type Output;
    fn add(self, rhs: RHS) -> Self::Output;
}

/*
impl Add for $t {
    type Output = $t;
    fn add(self, other: $t) -> $t {
        self + other
    }
}
*/

impl Add for u32 {
    type Output = u32;
    fn add(self, other: u32) -> u32 {
        self + other
    }
}

impl Add<&str> for String {
    type Output = String;
    fn add(mut self, other: &str) -> String {
        self.push_str(other);
        self
    }
}

fn main() {
    let a = "hello";
    let b = " world";
    let c = a.to_string() + b;

    println!("{:?}", c);
}