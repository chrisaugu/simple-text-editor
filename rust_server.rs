use actix_web::{web, App, HttpRequest, HttpServer, Responder};

// A simple handler that returns "hello\n"
async fn hello() -> impl Responder {
    "hello\n"
}

// A handler that echoes the request headers
async fn headers(req: HttpRequest) -> impl Responder {
    let mut response = String::new();
    for (name, value) in req.headers() {
        response.push_str(&format!("{}: {:?}\n", name, value));
    }
    response
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    // Start the HTTP server
    HttpServer::new(|| {
        App::new()
            .route("/hello", web::get().to(hello))
            .route("/headers", web::get().to(headers))
    })
    .bind("127.0.0.1:8090")?
    .run()
    .await
}