#[derive(Debug)]
struct Foo<'a> {
    part: &'a str,
}

impl<'a> Foo<'a> {
    fn split_first(s: &'a str) -> &'a str {
        s.split(',').next().expect("Can not find the ','")
    }

    fn new(s: &'a str) -> Self {
        Foo {
            part: Foo::split_first(s)
        }
    }

    fn get_part(&self) -> &str {
        self.part
    }
}

fn main() {
    let words = String::from("Sometimes think, the greatest sorrow than older");

    let foo = Foo::new(words.as_str());

    println!("{:?}", foo.get_part());
}