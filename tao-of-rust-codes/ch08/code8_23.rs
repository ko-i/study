fn main() {
    let s = " Hello\tworld\t";

    println!("{:?}", s.trim());
    println!("{:?}", s.trim_start());
    println!("{:?}", s.trim_end());
}