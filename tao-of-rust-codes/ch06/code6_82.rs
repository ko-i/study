fn main() {
    let arr = [1, 2, 3];
    let result1 = arr.iter().any(|&x| x != 2);
    let result2 = arr.iter().any(|x| *x != 2);

    println!("{:?}", result1);
    println!("{:?}", result2);
}