fn main() {
    println!("There's:");

    let v = vec!["antimony", "arsenic", "aluminum", "selenium"];

    for ele in &v {
        println!("{:?}", ele);
    }

    let v = vec!["antimony", "arsenic", "aluminum", "selenium"];

    let mut iter = (&v).into_iter();

    while let Some(ele) = iter.next() {
        println!("{:?}", ele);
    } 
}