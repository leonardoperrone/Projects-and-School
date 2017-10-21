import { Http } from "@angular/http";
export declare class CheckBoxService {
    private _http;
    responseData: any;
    parentRef: any;
    constructor(_http: Http);
    fetchData(parentRef: any, serviceUrl: string, methodType: string): void;
    setData(): void;
}
