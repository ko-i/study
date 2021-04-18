fn main() {
    let a = [1, 2, 3];

    println!("{:?}", a.iter().any(|x| *x != 2));

    let sum = a.iter().fold(0, |acc, x| acc + x);
    println!("{:?}", sum);
}