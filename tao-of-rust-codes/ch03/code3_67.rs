fn main() {
    let a: &'tatic str = "hello";
    let b: &str = a as &str;
    let c: &'static str = b as &'static str;
}