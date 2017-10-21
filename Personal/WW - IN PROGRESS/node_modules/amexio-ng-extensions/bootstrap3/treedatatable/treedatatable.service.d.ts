import { Http } from "@angular/http";
export declare class TreeDataTableService {
    private _http;
    parentRef: any;
    responseData: any;
    constructor(_http: Http);
    fetchData(parentRef: any, serviceUrl: string, methodType: string): void;
    setData(): void;
}
