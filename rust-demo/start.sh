docker run --name my-postgres-db -e POSTGRES_PASSWORD=secr3t -p 5432:5433 -d postgres:16-alpine
docker run -it --rm --network some-network postgres psql -h my-postgres-db -U postgres