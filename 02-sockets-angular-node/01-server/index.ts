import Server from "./classes/server";
import { router } from "./routes/router";
import bodyParser from "body-parser";
import cors from 'cors';



const server = Server.instance; // Al tener el constructor privado, no se pueden
// crear instancias de esta forma
server.app.use( bodyParser.urlencoded({ extended: true }) );
server.app.use( bodyParser.json() );

// Cors
server.app.use(cors({origin: true, credentials:true}));

// Rutas de servicios
server.app.use('/',router);




server.start(()=> console.log(
`Servidor Corriendo en el puerto ${server.port}`))

