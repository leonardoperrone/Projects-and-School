import { Http } from '@angular/http';
import { Observable } from "rxjs/Observable";
export declare class DropDownService {
    private _http;
    constructor(_http: Http);
    fetchData(serviceUrl: string, methodType: string): Observable<any>;
}
