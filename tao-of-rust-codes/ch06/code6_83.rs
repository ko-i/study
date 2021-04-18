fn main() {
    let arr = vec![1, 2, 3];

    let sum1 = arr.iter().fold(0, |acc, x| acc + x);
    let sum2 = arr.iter().fold(0, |acc, x| acc + *x);
    let sum3 = arr.iter().fold(0, |acc, &x| acc + x);
    let sum4 = arr.into_iter().fold(0, |acc, x| acc + x);

    println!("{:?}", sum1);
    println!("{:?}", sum2);
    println!("{:?}", sum3);
    println!("{:?}", sum4);
}