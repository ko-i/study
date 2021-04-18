use std::borrow::Cow;

fn abs_all(input: &mut Cow<[i32]>) {
    for i in 0..input.len() {
        let v = input[i];

        if v < 0 {
            input.to_mut()[i] = -v;
        }
    }
}

fn abs_sum(ns: &[i32]) -> i32 {
    let mut lst = Cow::from(ns);

    abs_all(&mut lst);

    lst.iter().fold(0, |acc, &n| acc + n)
}

fn main() {
    // no copy
    let s1 = [1, 2, 3];
    let mut i1 = Cow::from(&s1[..]);
    abs_all(&mut i1);
    println!("In: {:?}", s1);
    println!("Out: {:?}", i1);

    // copy
    let s2 = [1, 2, 3, -45, 5];
    let mut i2 = Cow::from(&s2[..]);
    abs_all(&mut i2);
    println!("In: {:?}", s2);
    println!("Out: {:?}", i2);

    let mut v1 = Cow::from(vec![1, 2, -3, 4]);
    abs_all(&mut v1);
    println!("In/Out: {:?}", v1);

    let s3 = [1, 3, 5, 6];
    let sum1 = abs_sum(&s3[..]);
    println!("{:?}", s3);
    println!("{:?}", sum1);

    // change and copy
    let s4 = [1, -3, 5, -6];
    let sum2 = abs_sum(&s4[..]);
    println!("{:?}", s4);
    println!("{:?}", sum2);
}