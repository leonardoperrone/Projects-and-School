import { Http } from "@angular/http";
export declare class FileUploadService {
    private _http;
    responseData: any;
    parentRef: any;
    constructor(_http: Http);
    uploadFile(parentRef: any, serviceUrl: string, methodType: string, requestData: any): void;
    setData(): void;
}
