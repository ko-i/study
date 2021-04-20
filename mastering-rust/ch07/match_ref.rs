struct Person(String);

fn main() {
    let a = Person("Richard Feynman".to_string());
    match a {
        Person(ref name) => println!("{} was a great physicist!", name),
        _ => panic!("Oh no!"),
    }

    let b = a;
}