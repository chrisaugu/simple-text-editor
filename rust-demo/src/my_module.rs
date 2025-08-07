pub struct MyCoolStruct {
    hello: String,
}

// default values for when you don't wanna initialize it
// with other stuff
impl Default for MyCoolStruct {
    fn default() -> Self {
        MyCoolStruct {
            hello: "world".to_string(),
        }
    }
}

pub fn my_public_func() {
    my_private_func();
}

fn my_private_func() {
    println!("Hello, I don't like world, I prefer to say earth!");
}

impl MyCoolStruct {
    pub fn my_curious_func(self) {
        // useful stuff goes here
        // that you want to call from other files
    }

    fn my_shy_func(self) {
        // logic internal to this struct goes here
    }
}

pub struct Cli {
    pub pattern: String,
    pub path: std::path::PathBuf,
}
